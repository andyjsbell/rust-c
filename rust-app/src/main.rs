extern crate libc;
//use libc::{c_int, size_t};
use std::time::{Instant};

#[link(name = "MyStaticLib", kind = "static")]
extern {
    fn SimpleMultiply(a: u32, b: u32) -> u32;
    fn FillMyMemory(buffer: *mut u8, size: *mut u32);
}

pub fn simple_multiply(a: u32, b: u32) -> u32 {
    unsafe {
        SimpleMultiply(a, b)
    }
}

pub fn fill_my_memory() -> Vec<u8> {
    unsafe {
        let mut dstlen = 1920 * 1028 * 4;
        let mut dst = Vec::with_capacity(dstlen as usize);
        let pdst = dst.as_mut_ptr();
        FillMyMemory(pdst, &mut dstlen);
        dst.set_len(dstlen as usize);
        dst
    }
}

fn main() {
    println!("Calling C {0} == {1}", 10 * 2, simple_multiply(10,2));

    let now = Instant::now();
    let mem = fill_my_memory();
    println!("ms {}", now.elapsed().as_millis());
    println!("Index 0 from C {0} {1}", mem[0], mem[1]);
}
