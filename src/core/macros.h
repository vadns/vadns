#ifndef _VADNS_CORE_MACROS_H_INCLUDED_
#define _VADNS_CORE_MACROS_H_INCLUDED_

#define VADNS_ALLOW_MOVE_ONLY(TypeName) \
    TypeName(TypeName&& other) noexcept; \
    TypeName(const TypeName&) = delete; \
    void operator =(const TypeName&) = delete; \


#endif  // _VADNS_CORE_MACROS_H_INCLUDED_
