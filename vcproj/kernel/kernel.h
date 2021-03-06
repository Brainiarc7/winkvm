
#ifndef _KERNEL_H_
#define _KERNEL_H_

#include "init.h"

#define KERN_EMERG      "<0>"   /* system is unusable                   */
#define KERN_ALERT      "<1>"   /* action must be taken immediately     */
#define KERN_CRIT       "<2>"   /* critical conditions                  */
#define KERN_ERR        "<3>"   /* error conditions                     */
#define KERN_WARNING    "<4>"   /* warning conditions                   */
#define KERN_NOTICE     "<5>"   /* normal but significant condition     */
#define KERN_INFO       "<6>"   /* informational                        */
#define KERN_DEBUG      "<7>"   /* debug-level messages                 */

#define INTERNAL_SYSCALL_ERRNO(val, err) (-(val))
#define INTERNAL_SYSCALL_ERROR_P(val, err) \
	((unsigned int) (val) >= 0xfffff001u)

/* This is the position that returning -1 of ioctl */
/* in glibc sysdeps/unix/sysv/linux/i386/sysdep.h  */
/* #undef INLINE_SYSCALL */
/* #define INLINE_SYSCALL(name, nr, args...) \ */
/*   ({                                          \ */
/*     unsigned int resultvar = INTERNAL_SYSCALL (name, , nr, args);         \ */
/*     if (__builtin_expect (INTERNAL_SYSCALL_ERROR_P (resultvar, ), 0))         \ */
/*       {                                       \ */
/*     __set_errno (INTERNAL_SYSCALL_ERRNO (resultvar, ));           \ */
/*     resultvar = 0xffffffff;                           \ */
/*       }                                       \ */
/*     (int) resultvar; }) */

int _cdecl printk(const char *s, ...);
void _cdecl get_page(struct page *page);

void dump_hex(unsigned char *buffer, int len, int row);

/*
 * Address types:
 *
 *  gva - guest virtual address
 *  gpa - guest physical address
 *  gfn - guest frame number
 *  hva - host virtual address
 *  hpa - host physical address
 *  hfn - host frame number
 */

typedef unsigned long  gva_t;
typedef u64            gpa_t;
typedef unsigned long  gfn_t;

typedef unsigned long  hva_t;
typedef u64            hpa_t;
typedef unsigned long  hfn_t;

//#pragma pack(pop)

ULONG KeQueryActiveProcessorCountCompatible(OUT PKAFFINITY ActiveProcessors);
int _cdecl atomic_dec_and_test(int *v);
int _cdecl atomic_inc_and_test(int *v);

#define MEM_TAG 'HmmV'

/* for DEBUG */
//#define FUNCTION_ENTER()       printk(KERN_ALERT " --> %s\n", __FUNCTION__)
//#define FUNCTION_EXIT()        printk(KERN_ALERT " <-- %s\n", __FUNCTION__)

#define FUNCTION_ENTER()
#define FUNCTION_EXIT()

#define PAGE_MASK (~(PAGE_SIZE-1))

void* _cdecl __va(unsigned long addr);
u64 _cdecl __pa(hva_t virt);
hpa_t _cdecl get_phys(PHYSICAL_ADDRESS *addr);

#define __INIT(x) (x) /* This macro declare initializer function to use */
#define __RELEASE(x) (x) /* This macro declare destructor function to use */

#endif
