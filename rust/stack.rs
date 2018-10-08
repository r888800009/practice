fn main()
{
    let mut stack: Vec<i32> = Vec::new();
    
    for x in 0..10 {
        stack.push(x);
    }
    
    while !stack.is_empty() {
        print!("{:?}\n", stack);
        stack.pop();

    }
}

