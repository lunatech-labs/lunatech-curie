extern crate curie;
use curie::parser;

use std::io::{self, BufRead};

fn main() {
    assert_eq!(parser::hex_color("#2F14DF"), Ok(("", parser::Color {red: 47, green: 20, blue: 223, })));
    let stdin = io::stdin();
    for line in stdin.lock().lines() {
        let input_line = line.unwrap();
        let result = parser::hex_color(&input_line).unwrap().1;
        println!("{:?}", result);
    }
}
