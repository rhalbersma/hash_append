//-------------------------------- endian.h ------------------------------------
// 
// This software is in the public domain.  The only restriction on its use is
// that no one can remove it from the public domain by claiming ownership of it,
// including the original authors.
// 
// There is no warranty of correctness on the software contained herein.  Use
// at your own risk.
// 
//------------------------------------------------------------------------------

#ifndef ENDIAN_H
#define ENDIAN_H

namespace xstd
{

// endian provides answers to the following questions:
// 1.  Is this system big or little endian?
// 2.  Is the "desired endian" of some class or function the same as the
//     native endian?

#ifdef _MSC_VER

#define __ORDER_LITTLE_ENDIAN__ 1234
#define __ORDER_BIG_ENDIAN__    4321
#define __BYTE_ORDER__          __ORDER_LITTLE_ENDIAN__

#endif

enum class endian
{
    native = __BYTE_ORDER__,
    little = __ORDER_LITTLE_ENDIAN__,
    big    = __ORDER_BIG_ENDIAN__
};

static_assert(endian::native == endian::little ||
              endian::native == endian::big,
              "endian::native shall be one of endian::little or endian::big");

static_assert(endian::big != endian::little,
              "endian::big and endian::little shall have different values");

}  // xstd

#endif  // ENDIAN_H
