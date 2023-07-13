use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};
use std::collections::HashMap;
use std::cmp::Reverse;

fn main() {
    let args: Vec<String> = std::env::args().collect();

    if args.len() != 3 {
        println!("Usage: <program> <file_path> <number_of_words>");
        return;
    }

    let file_path = &args[1];
    let num_words = args[2].parse::<usize>().expect("number_of_words must be a positive integer");

    let file = File::open(file_path);

    let file = match file {
        Ok(file) => file,
        Err(error) => {
            println!("Failed to open file: {}", error);
            return;
        }
    };

    let reader = BufReader::new(file);
    let mut word_count: HashMap<String, usize> = HashMap::new();

    for line in reader.lines() {
        let line = match line {
            Ok(line) => line,
            Err(error) => {
                println!("Failed to read line: {}", error);
                continue;
            }
        };

        let words: Vec<&str> = line.split_whitespace().collect();

        for word in words {
            let word = word.to_string();
            let count = word_count.entry(word).or_insert(0);
            *count += 1;
        }
    }
    let mut word_count_vec: Vec<(&String, &usize)> = word_count.iter().collect();
    word_count_vec.sort_by(|a, b| b.1.cmp(a.1));

    for (i, &(word, &count)) in word_count_vec.iter().enumerate() {
        if i >= num_words {
            break;
        }
        println!("{}: {}", word, count);
    }
}
