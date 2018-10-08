struct MinStack {
    stack    : Vec<i32>,
    min_stack : Vec<i32>
}

impl MinStack {
    fn top(&mut self) -> i32
    {
        self.stack.last().unwrap().clone()
    }

    fn pop(&mut self)
    {
        self.stack.pop();
        self.min_stack.pop();
    }

    fn push(&mut self, num : i32)
    {
        if self.stack.is_empty() {
            self.min_stack.push(num);

        } else {
            let min = self.min_stack.last().clone().unwrap().clone();
            if min > num {
                self.min_stack.push(num);
            } else {
                self.min_stack.push(min);
            }
        }
        self.stack.push(num);
    }

    fn min(&mut self) -> i32
    {
        self.min_stack.last().unwrap().clone()
    }

}

fn main()
{
    let mut stack = MinStack {
        stack    : Vec::new(),
        min_stack : Vec::new()
    }; 
    stack.push(3);
    print!("{:?}, {:?}\n", stack.top(), stack.min());
    stack.push(5);
    print!("{:?}, {:?}\n", stack.top(), stack.min());
    stack.push(2);
    print!("{:?}, {:?}\n", stack.top(), stack.min());
    stack.push(8);
    print!("{:?}, {:?}\n", stack.top(), stack.min());
    stack.push(9);
    print!("{:?}, {:?}\n", stack.top(), stack.min());

    println!("pop!()");

    stack.pop();
    print!("{:?}, {:?}\n", stack.top(), stack.min());
    stack.pop();
    print!("{:?}, {:?}\n", stack.top(), stack.min());

}

