/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif

//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */

int bitXor(int x, int y) {
  return (~(x&y))&(~((~x)&(~y)));
}

/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */

int tmin(void) {
  return 1 << 31;
}

//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */

int isTmax(int x) {

  //&&与&区别：两者都表示“与”运算，但是&&运算符第一个表达式不成立的话，后面的表达式不运算，直接返回。而&对所有表达式都得判断。
  //那我们首先看,答案的要求是返回0或者1,而且给出的操作符是有限的,我们可以通过!来使得返回的值是0或者1
  //Step1.补码的最大值我们知道是0111 1111(这里以八位为例子,32位也一样的)
  //Step2.我们根据一些性质:最大值+1(0111 1111 + 0000 0001)等于最小值(1000 0000)
  //Step3.我们上面有提到就是可以通过！来返回0或者1的结果,那我们是不是现在有两个选择,让!()的括号中的值为1或者0
  //Step4.那么第一种情况是如果里面的是0,那怎么得到0呢,我们发现
  //Step5.我们观察一开始通过最大值+1得到的最小值(1000 0000)以及最大值(0111 1111),它们两个进行异或(不进位加法)和与(操作)可以分别得到0和1,那么就有!后分别是1和0
  //Step6.如果进行与操作的话,固然可以,但是这是不对的,假如x是0000 0000,那么x+1我们会得到0000 0001,此时的话,x和x+1进行与操作我们就会得到0000 0000,然后!后也是得到1,但是x不是最大值
  //Step7.那么答案就是另外一个了,最大值和最小值异或必然得到1,证明很简单,最大值除了最高位是0,其他都是1,最小值最最高位是0,其他位都是1,那么异或肯定会得到1
  //Step8.那我们是不是就有return !(x^x+1),也就是如果x是最大值的话,那我们可以返回1,相反,同时如果不是最大值那么就会返回0
  //Step9.考虑特殊情况-1,-1的1原码最高位改成1,然后我们一般用补码表示负数,-1的源码1000 0001,那么-1的补码就是1111 1111
  //Step10.但是的话-1+1然后和-1进行异或操作会得到全是1
  return (!((~(x+1))^x)) & (!!(x+1));
  //首先前面一个数+1之后取反等于本身只有两个情况:一个是可以知道这个数就是最大值(0111 1111),另外一个情况也可能是(1111 1111)
  //结果都是要返回1,所以加了个!
  //本题需要的是最大值,自然就是需要排除另外-1的情况,也就是如果是-1就返回0,不是-1就返回1
  //如果是-1,要想想(0000 0001)和(1111 1111)
  //x ^ (~(x+1)) 此时是满足最大值的,但是要返回1,最大值+1取反还是等于最大值,然后用异或表示最大值+1和最大值相等,两个相等的数异或是0,由于最大的数要返回1,就加个!
  //此时还要判断是不是-1,是-1,就返回0,否则返回1
  //我们直接假设是-1(1111 1111)那么(-1+1)是(0000 0000)然后取!!还是0000 0000,那么和前面的与就是0了
  //如果x是-1,那-1+1=0,!!0还是0,0和前面的&,就是0,所以返回0,没问题
  //反正不是-1,那x就是0111 1111,然后+1等于1000 0000,然后!!就是1,和前面异或,结果还是1
  //因此答案是正确的
  //如果是-1,后面就会返回0,如果不是就会返回1,这么一来就可以区分是不是-1了
}

/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */

int allOddBits(int x) {
  int x1 = 0xaa;
  int x2 = (x1 << 8) | x1;
  int x3 = (x2 << 16) | x2;
  return !((x3 & x) ^ x3);
}

/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */

int negate(int x) {
  return ~x+1;
}

//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */

int isAsciiDigit(int x) {
  int a = x >> 4;
  int b = x & 15;
  return (!(a ^ 3)) & (!(b ^ 8) | !(b & 6));
}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */

int conditional(int x, int y, int z) {
  int r = !!x;
  r = (~r) + 1;
  return (r&y) ^ (~r&z);
}

/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */

int isLessOrEqual(int x, int y) {
  int mask = 0x1;
  int equals = !(x ^ y);
  int x_sign = (x >> 31) & mask;
  int y_sign = (y >> 31) & mask;
  int diff_sign = x_sign ^ y_sign;
  int case2 = diff_sign & x_sign;
  int neg_y = (~y) + 1;
  int less = ((x + neg_y) >> 31) & mask;
  return equals | case2 | (!diff_sign & less);
  //a = 0000 1100
  //b = 0000 1001
  //二进制01103的十进制是
  //0000 1100  - 0000 1001 = 0000 0011
  //0x7fffffff的二进制是1111 1111 1111 1111 1111 1111 1111 1111取反后是
  //7的二进制是0000 0000 0000 0000 0000 0000 0000 0111
  //1111 1111 1111 1111 1111 1111 1111 0100+1=1111 1111 1111 1111 1111 1111 1111 1111 0101
}

//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */

int logicalNeg(int x) {
  //0的二进制是0000 0000 0000 0000 0000 0000 0000 0000
  //-1的二进制是1111 1111 1111 1111 1111 1111 1111 1111 
  //和1做个与操作即可0000 0000 0000 0000 0000 0000 0000 0001
  //结果为0000 0000 0000 0000 0000 0000 0000 0001就是结果是1
  //反之结果是-1
  return ~((x | (-x+1)) >> 31) & 1;
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */

int howManyBits(int x) {
  int b16,b8,b4,b2,b1,b0;
  int sign=x>>31;
  x = (sign&~x)|(~sign&x);//如果x为正则不变，否则按位取反（这样好找最高位为1的，原来是最高位为0的，这样也将符号位去掉了）
  // 不断缩小范围
  b16 = !!(x>>16)<<4;//高十六位是否有1
  x = x>>b16;//如果有（至少需要16位），则将原数右移16位
  b8 = !!(x>>8)<<3;//剩余位高8位是否有1
  x = x>>b8;//如果有（至少需要16+8=24位），则右移8位
  b4 = !!(x>>4)<<2;//同理
  x = x>>b4;
  b2 = !!(x>>2)<<1;
  x = x>>b2;
  b1 = !!(x>>1);
  x = x>>b1;
  b0 = x;
  return b16+b8+b4+b2+b1+b0+1;//+1表示加上符号位
}

/*
代码来源于网络
通过二分法，查找出1的最高位
*/
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */

unsigned floatScale2(unsigned uf) {
  int signal = (uf)&(1<<31);
  unsigned exp = (uf>>23);
  unsigned clearBits;
  
  if((exp&0xff)==0x0)
  {
    return (uf<<1)|signal;
  }
  //NAN
  if((exp&0xff)==0xff)
  {
      return uf;
  }

  exp = exp+1;
  //NAN
  if((exp&0xff)==0xff)
  {
      return 0x7f800000|signal;
  }
  exp = exp<<23;
  clearBits = 0x807fffff;

  uf = uf&clearBits;
  uf = uf|exp;
  return uf;
}

/*思路
取符号位，exp，若为NAN或0，可简单操作后直接返回。
若exp+1后成为nan，也可直接范围。
否则将exp替换为新的exp即可。
*/

/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */

int floatFloat2Int(unsigned uf) {
    unsigned exp = (uf>>23)&0xff;
    unsigned tmp;
    int shift;
    int signal;
    int clearBits;
    int setBits;
    if((exp)<127) return 0;
    if((exp)>159) return 0x80000000u;
    tmp = uf;
    signal = (uf>>31)&0x1;
    shift = 23-(exp-127);
    if((exp&0xff)!=0)
    {
        exp = exp-127;
        tmp = tmp>>shift;
        clearBits = ~(0xffffffff<<(exp));
        setBits = 0x1<<(exp);
        tmp = tmp&clearBits;
        tmp = tmp|setBits;
        if(signal==0) return tmp;
        else return (~tmp)+1;
    }else
    {
        return 0;
    }
}

/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */

unsigned floatPower2(int x) {
  unsigned exp;
  unsigned signal;
  unsigned ret;
  if(x>127) return 0x7f800000;
  if(x<-126) return 0;
  exp = x+127;
  signal = 0x0<<31;
  exp = exp<<23;
  ret = 0;
  return ret|exp|signal;
}
