use std::iter::FromIterator;

// (abc 1 2)

// 1. open paren, n symbols, close paren

// condition to finish: space or paren
pub fn symbol(input: &str) -> &str {
    let mut parsed: Vec<char> = Vec::new();
    let mut pos = 0;
    let mut finished = false;
    while !finished {
        // let character = input[pos];
        let character = input.chars().nth(pos);
        if character == ')' || character == ' ' {
            finished = true;
        } else {
            parsed.push(character);
        }
        pos += 1;
    }
    return &String::from_iter(parsed.into_iter());
}
