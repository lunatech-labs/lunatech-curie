use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    for line in stdin.lock().lines() {
        let result = line.unwrap();
        println!("{}", result);
    }
}
