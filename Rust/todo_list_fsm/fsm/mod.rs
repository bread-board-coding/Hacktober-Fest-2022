use std::{io, num::IntErrorKind};
use crate::{TodoEntry, util};

pub enum OwnState {
    Idle,
    ShowEntries,
    AddEntry,
    RemoveEntry,
}

pub struct GlobalContext {
    pub todo_entries: Vec<TodoEntry>,
    pub user_input: Option<i32>,
    pub current_state: OwnState
}

impl GlobalContext {
    pub fn new() -> GlobalContext {
        let todo_entries: Vec<TodoEntry> = Vec::new();
        let user_input = None;
        let current_state = OwnState::Idle;
        
        GlobalContext {
            todo_entries,
            user_input,
            current_state,
        }
    }
}

pub fn state_logic(context: &mut GlobalContext) {
    match context.current_state {
        OwnState::Idle => {
            if context.user_input.is_some() {
                let user_input: i32 = context.user_input.unwrap();
                let user_input = util::int_to_menu_option(user_input);

                match user_input {
                    crate::MenuOption::ShowEntries => {
                        context.current_state = OwnState::ShowEntries;
                    },
                    crate::MenuOption::AddEntry => {
                        context.current_state = OwnState::AddEntry;
                    },
                    crate::MenuOption::RemoveEntry => {
                        context.current_state = OwnState::RemoveEntry;
                    },
                    crate::MenuOption::Exit => {
                        println!("good bye!");
                        std::process::exit(0);
                    }
                };
            }
        },
        _ => context.current_state = OwnState::Idle,
    }
}

pub fn output_logic(context: &mut GlobalContext) {
    match context.current_state {
        OwnState::ShowEntries => {
            let mut idx: u8 = 0;
            for entry in context.todo_entries.iter() {
                println!("entry {}: {}", idx, entry.description);
                idx = idx + 1;
            }
        },

        OwnState::AddEntry => {
            println!("enter entry description");
            let mut description = String::new();
            let result = io::stdin().read_line(&mut description);
            match result {
                Ok(_) => {
                    let new_entry: TodoEntry = TodoEntry { description };
                    println!("added entry {:?}", new_entry);
                    context.todo_entries.push(new_entry);
                },
                Err(_) => println!("could not read description"),
            };
        },

        OwnState::RemoveEntry => {
            println!("enter entry index");
            let mut idx: u8 = 0;
            for entry in context.todo_entries.iter() {
                println!("entry {}: {}", idx, entry.description);
                idx = idx + 1;
            }
            let mut idx = String::new();
            let result = io::stdin().read_line(&mut idx);
            match result {
                Ok(_) => {
                    let result = idx.trim().parse::<i32>();
                    match result {
                        Ok(result) => {
                            if (result as usize) > context.todo_entries.len() || result < 0 {
                                println!("given index is not valid!");
                                return;
                            }

                            context.todo_entries.remove(result as usize);
                            println!("removed index {}", result);
                        },
                        Err(error) => {
                            match error.kind() {
                                IntErrorKind::Empty => (),
                                _ => println!("could not parse index, {:?}", error)
                            };
                        },
                    };

                },
                Err(_) => println!("could not read index"),
            };
        },

        _ => (),
    };
}