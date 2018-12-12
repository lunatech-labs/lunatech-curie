extern crate curie;
use curie::scanner;

use std::io::{self, BufRead};
use std::str;

fn main() {
    let symbol = String::from("abc");
    println!("{:?}", scanner::symbol(&symbol));

    // assert_eq!(parser::hex_color("#2F14DF"), Ok(("", parser::Color {red: 47, green: 20, blue: 223, })));
    // let stdin = io::stdin();

    // for line in stdin.lock().lines() {
    //     let input_line = line.unwrap();
    //     let result = parser::hex_color(&input_line).unwrap().1;
    //     println!("{:?}", result);
    // }
}
