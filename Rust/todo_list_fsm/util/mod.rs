use crate::MenuOption;
use std::{ io, num::IntErrorKind };

pub fn read_raw_input() -> Option<i32> {
    let mut input = String::new();
    let result = io::stdin().read_line(&mut input);

    match result {
        Ok(_) => {
            let input = input.trim().parse::<i32>();
            match input {
                Ok(result) => Some(result),
                Err(error) => {
                    match error.kind() {
                        IntErrorKind::Empty => (),
                        _ => println!("could not parse stdin, {:?}", error)
                    };
                    None
                },
            }
        },
        Err(_) => {
            None
        },
    }
}

pub fn int_to_menu_option(int: i32) -> MenuOption {
    match int {
        1 => MenuOption::ShowEntries,
        2 => MenuOption::AddEntry,
        3 => MenuOption::RemoveEntry,
        _ => MenuOption::Exit,
    }
}