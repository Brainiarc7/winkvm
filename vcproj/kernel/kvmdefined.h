
#ifndef _KVMDEFINED_H_
#define _KVMDEFINED_H_

#include <linux/kvm.h>

extern unsigned num_msrs_to_save;
extern u32 msrs_to_save[];
extern u32 emulated_msrs[];

extern unsigned long _cdecl get_emulated_msrs_array_size(void);

/* start linux device driver */
extern int _cdecl vmx_init(void);
extern void _cdecl vmx_exit(void);
/* end linux device driver */

/* dev */
extern int _cdecl kvm_dev_ioctl_create_vm(void);

/* vm */
extern int _cdecl kvm_vm_ioctl_set_memory_region(struct kvm *kvm, struct kvm_memory_region *mem);
extern int _cdecl kvm_vm_ioctl_create_vcpu(struct kvm *kvm, int n);
extern int _cdecl kvm_vm_ioctl_get_dirty_log(struct kvm *kvm, struct kvm_dirty_log *log);
extern int _cdecl kvm_read_guest(struct kvm_vcpu *vcpu, gva_t addr, unsigned long size, void *dest);
extern int _cdecl kvm_write_guest(struct kvm_vcpu *vcpu, gva_t addr, unsigned long size, void *data);
extern int _cdecl kvm_vm_release(struct inode *inode, struct file *filp);

/* vcpu */
extern int _cdecl kvm_vcpu_ioctl_run(struct kvm_vcpu *vcpu, struct kvm_run *kvm_run);
extern int _cdecl kvm_vcpu_ioctl_set_regs(struct kvm_vcpu *vcpu, struct kvm_regs *regs);
extern int _cdecl kvm_vcpu_ioctl_get_regs(struct kvm_vcpu *vcpu, struct kvm_regs *regs);
extern int _cdecl kvm_vcpu_ioctl_set_sregs(struct kvm_vcpu *vcpu, struct kvm_sregs *sregs);
extern int _cdecl kvm_vcpu_ioctl_get_sregs(struct kvm_vcpu *vcpu, struct kvm_sregs *sregs);
extern int _cdecl kvm_vcpu_ioctl_translate(struct kvm_vcpu *vcpu, struct kvm_translation *tr);
extern int _cdecl kvm_vcpu_ioctl_interrupt(struct kvm_vcpu *vcpu, struct kvm_interrupt *irq);
extern int _cdecl kvm_vcpu_release(struct inode *inode, struct file *filp);

extern int _cdecl check_function_pointer_test(void);

/*
 * Read or write a bunch of msrs. Parameters are user addresses.
 *
 * @return number of msrs set successfully.
 */
extern int _cdecl msr_io(struct kvm_vcpu *vcpu, struct kvm_msrs *user_msrs,
						 int (_cdecl *do_msr)(struct kvm_vcpu *vcpu, 
						 unsigned index, u64 *data),
						 int writeback);

/*
 * Adapt set_msr() to msr_io()'s calling convention
 */
int _cdecl do_set_msr(struct kvm_vcpu *vcpu, unsigned index, u64 *data);
int _cdecl get_msr(struct kvm_vcpu *vcpu, u32 msr_index, u64 *pdata);

#endif
