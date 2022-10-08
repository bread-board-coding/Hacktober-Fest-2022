mod fsm;
mod util;

pub enum MenuOption {
    ShowEntries = 0,
    AddEntry,
    RemoveEntry,
    Exit
}

#[derive(Debug)]
pub struct TodoEntry {
    pub description: String
}

fn print_welcome() {
    println!("Hello, there!"); 
    println!("Welcome to the worst rust todo-list");
    println!("Please, follow up the instructions");
}

fn print_menu() {
    println!("MENU");
    println!("1. Show Todo entries");
    println!("2. Add new Todo entry");
    println!("3. Remove existing Todo entry");
    println!("4. Exit");
}

fn main() {
    let mut context = fsm::GlobalContext::new();

    print_welcome();
    print_menu();

    loop {
        let mut input: Option<i32> = None;
        match context.current_state {
            fsm::OwnState::Idle => {
                input = util::read_raw_input();
            },
            _ => ()
        };

        context.user_input = input;

        fsm::state_logic(&mut context);
        fsm::output_logic(&mut context);
    }

}