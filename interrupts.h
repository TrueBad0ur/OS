struct idt_entry_struct {
    unsigned short offset_1;  // offset bits 0..15
    unsigned short sel;       // Kernel segment selector.
    unsigned char  zero;      // unused, set to 0
    unsigned char  type_attr; // type and attributes, see below
    unsigned short offset_2;  // offset bits 16..31
} __attribute__((packed));

typedef struct idt_entry_struct idt_entry_t; 

struct idt_ptr_struct {
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

typedef struct idt_ptr_struct idt_ptr_t;

typedef struct _stack_with_err_code {
   unsigned int ds;                                     // Data segment selector
   unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
   unsigned int int_no, err_code;                       // Interrupt number and error code (if applicable)
   unsigned int eip, cs, eflags, useresp, ss;           // Pushed by the processor automatically.
}  stack_with_err_code;

struct _stack_without_err_code {
   unsigned int ds;                                     // Data segment selector
   unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
   unsigned int int_no;
   unsigned int eip, cs, eflags, useresp, ss;           // Pushed by the processor automatically.
}  __attribute__((packed));
typedef struct _stack_without_err_code stack_without_err_code;

typedef void (*irq_handler)(stack_with_err_code);
