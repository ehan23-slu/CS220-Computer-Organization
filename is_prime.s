/**
 * Returns true if the provided number is prime or false otherwise
 * Precondition: n >= 2
 *
 * This function corresponds to the C funtion:
 *  long is_prime(long n);
 *
 * Parameter:
 *  n - the number which can be either prime or not
 * 
 * Return value:
 *  return 1 if the number is prime
 *  return 0 if the number is not prime
 * 
 * Example:
 *  is_prime(11) - return 1 (true)
 *  is_prime(4) - return 0 (false)
 *
 * Resource:
 *  Textbook 1.3.1. - Boolean Values in C
 */

.arch armv8-a
.global is_prime

.text
.align 2

is_prime:
    // x0 - n 
    // x1 - i (divisor)

    // check the case where n == 2, which is prime
    mov x1, #2
    cmp x0, x1
    b.eq prime          // if n == 2, jump to prime label

    mov x1, #2          // initialize divisor i = 2

check:
    // if i * i > n, then n is prime
    mul x2, x1, x1      // x2 = i * i
    cmp x2, x0
    b.gt prime          // if i * i > n, jump to prime label

    // if n % i == 0, then n is not prime
    udiv x2, x0, x1    // x2 = n / i
    mul x3, x2, x1     // x3 = (n / i) * i
    cmp x3, x0
    b.eq not_prime     // if n is divisible, jump to not_prime label

    add x1, x1, #1     // increment i by 1
    b check            // repeat the check loop

prime:
    // return 1 (true) since n is prime
    mov x0, #1         // set return value to 1
    ret

not_prime:
    // return 0 (false) since n is not prime
    mov x0, #0         // set return value to 0
    ret
