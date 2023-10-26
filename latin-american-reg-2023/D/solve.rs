use std::io;

const DEBUG: bool = false;

fn exists_letter(word: String, cur_letter: char) -> bool {
    for letter in word.chars() {
        if letter == cur_letter {
            return true;
        }
    }
    if DEBUG {
        println!("{} {} not exists", cur_letter, word);
    }
    return false;
}

fn get_idx_char(word: String, idx: usize) -> char {
    return word.chars().nth(idx).unwrap();
}
fn main() {
    let n: usize;
    let g: usize;
    let mut words: Vec<String> = Vec::new();
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
    
    n = input.trim().parse().unwrap();
    
    for _ in 0..n {
        input = String::new();
        let _ = io::stdin().read_line(&mut input);
        words.push(input.clone());
    }
    
    input = String::new();
    let _ = io::stdin().read_line(&mut input);
    g = input.trim().parse().unwrap();
    let secret = words[0].clone();
    for _ in 0..g {
        input = String::new();
        let _ = io::stdin().read_line(&mut input);
        if DEBUG {
            println!("pattern: {}", input);
        }
        let mut ans: usize = 0;
        for word in &words {
            if DEBUG {
                println!("cur_word: {}", word);
            }
            let mut idx: usize = 0;
            let mut ok: usize = 0;
            for c in input.chars() {
                let cur_word_letter = get_idx_char(word.to_string(), idx);
                let secret_letter = get_idx_char(secret.to_string(), idx);
                if c == 'X' {
                    if !exists_letter(secret.clone(), cur_word_letter) {
                        ok += 1;
                    }
                } else if c == '*' {
                    if cur_word_letter == secret_letter {
                        ok += 1;
                    }
                } else {
                    if cur_word_letter != secret_letter && exists_letter(secret.clone(), cur_word_letter) {
                        ok += 1;
                    }
                }
                idx += 1;
            }
            if ok == 5 {
                ans += 1;
            }
        }
        println!("{}", ans);
    }
    if DEBUG {
        for word in &words {
            println!("{}", word);
        }
    }
}