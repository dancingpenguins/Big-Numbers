#include "pch.h"
#include <Math/Expression/NewOpCode.h>

#pragma warning(disable : 4073)
#pragma init_seg(lib)

#define DEFNAME(type,id,...) type id(_T(#id),__VA_ARGS__)

DEFNAME(Opcode0Arg       ,  RET   ,0xC3    );              // Near return to calling procedure
DEFNAME(Opcode0Arg       ,  CMC   ,0xF5    );              // Complement carry flag
DEFNAME(Opcode0Arg       ,  CLC   ,0xF8    );              // Clear carry flag     CF = 0
DEFNAME(Opcode0Arg       ,  STC   ,0xF9    );              // Set   carry flag     CF = 1
DEFNAME(Opcode0Arg       ,  CLI   ,0xFA    );              // Clear interrupt flag IF = 0
DEFNAME(Opcode0Arg       ,  STI   ,0xFB    );              // Set   interrupt flag IF = 1
DEFNAME(Opcode0Arg       ,  CLD   ,0xFC    );              // Clear direction flag DF = 0
DEFNAME(Opcode0Arg       ,  STD   ,0xFD    );              // Set   direction flag DF = 1

#ifdef IS64BIT
DEFNAME(Opcode0Arg       ,  CLGI  ,0x0F01DD);              // Clear Global Interrupt Flag
DEFNAME(Opcode0Arg       ,  STGI  ,0x0F01DC);              // Set Global Interrupt Flag
#endif // IS64BIT

#ifdef IS32BIT
DEFNAME(Opcode0Arg       ,  PUSHFD,0x9C);                  // Push EFLAGS onto stack *--SP = FLAGS;
DEFNAME(Opcode0Arg       ,  POPFD ,0x9D);                  // Pop  EFLAGS register from stack FLAGS = *SP++
DEFNAME(Opcode0Arg       ,  PUSHF ,PUSHFD,REGSIZE_WORD);   // Push FLAGS  onto stack *--SP = FLAGS;
DEFNAME(Opcode0Arg       ,  POPF  ,POPFD ,REGSIZE_WORD);   // Pop  FLAGS  register from stack FLAGS = *SP++
#else
DEFNAME(Opcode0Arg       ,  PUSHFQ,0x9C);                  // Push RFLAGS onto stack *--SP = FLAGS;
DEFNAME(Opcode0Arg       ,  POPFQ ,0x9D);                  // Pop  RFLAGS register from stack FLAGS = *SP++
DEFNAME(Opcode0Arg       ,  PUSHF ,PUSHFQ,REGSIZE_WORD);   // Push FLAGS  onto stack *--SP = FLAGS;
DEFNAME(Opcode0Arg       ,  POPF  ,POPFQ ,REGSIZE_WORD);   // Pop  FLAGS  register from stack FLAGS = *SP++
#endif // IS46BIT

DEFNAME(Opcode0Arg       ,  SAHF  ,0x9E);                  // Store AH into FLAGS
DEFNAME(Opcode0Arg       ,  LAHF  ,0x9F);                  // Load FLAGS into AH register
#ifdef IS32BIT
DEFNAME(Opcode0Arg       ,  PUSHAD,0x60);                  // Push all double-word (32-bit) registers onto stack
DEFNAME(Opcode0Arg       ,  POPAD ,0x61);                  // Pop  all double-word (32-bit) registers from stack
#endif // IS32BIT

DEFNAME(Opcode0Arg       ,  NOOP  ,0x90);
DEFNAME(Opcode2Arg       ,  ADD   ,0x00);
DEFNAME(Opcode2Arg       ,  OR    ,0x08);
DEFNAME(Opcode2Arg       ,  ADC   ,0x10);
DEFNAME(Opcode2Arg       ,  SBB   ,0x18);
DEFNAME(Opcode2Arg       ,  AND   ,0x20);
DEFNAME(Opcode2Arg       ,  SUB   ,0x28);
DEFNAME(Opcode2Arg       ,  XOR   ,0x30);
DEFNAME(Opcode2Arg       ,  CMP   ,0x38);
DEFNAME(OpcodeXchg       ,  XCHG       );                  // Exchange Two operands
DEFNAME(OpcodeMov        ,  MOV        );
DEFNAME(OpcodeLea        ,  LEA   ,0x8D);                  // Load effective address

DEFNAME(OpcodePushPop    ,  PUSH  ,0x50, 0xFF, 0x68, 6);
DEFNAME(OpcodePushPop    ,  POP   ,0x58, 0x8F, 0   , 0);

DEFNAME(OpcodeIncDec     ,  INC   ,0xFE,0);
DEFNAME(OpcodeIncDec     ,  DEC   ,0xFE,1);

//        Non existing opcode (0xF6,1);
DEFNAME(Opcode1Arg       ,  NOT   ,0xF6,2);                // Negate the operand, logical NOT
DEFNAME(Opcode1Arg       ,  NEG   ,0xF6,3);                // Two's complement negation
DEFNAME(Opcode1Arg       ,  MUL   ,0xF6,4);                // Unsigned multiply (ax = al*src, dx:ax=ax*src, edx:eax=eax*src, rdx:rax=rax*src)
DEFNAME(OpcodeIMul       ,  IMUL         );                // Signed multiply   (ax = al*src, dx:ax=ax*src, edx:eax=eax*src, rdx:rax=rax*src)
DEFNAME(Opcode1Arg       ,  DIV   ,0xF6,6);                // Unsigned divide   (ax/=src,al=quot,ah=rem,    edx:eax/=src,eax=quot,edx=rem,  rdx:rax/=src,rax=quit,rdx=rem
DEFNAME(Opcode1Arg       ,  IDIV  ,0xF6,7);                // Signed divide   ax      /= src, ah  must contain sign extension of al . al =quot, ah =rem
                                                           //                 dk:ax   /= src. dx  must contain sign extension of ax . ax =quot, dx =rem
                                                           //                 edx:eax /= src. edx must contain sign extension of eax. eax=quot, edx=rem
                                                           //                 rdx:rax /= src. rdx must contain sign extension of rax. rax=quot, rdx=rem

DEFNAME(OpcodeShiftRot   ,  ROL   ,0     );                // Rotate left  by cl/imm
DEFNAME(OpcodeShiftRot   ,  ROR   ,1     );                // Rotate right by cl/imm
DEFNAME(OpcodeShiftRot   ,  RCL   ,2     );                // Rotate left  by cl/imm (with carry)
DEFNAME(OpcodeShiftRot   ,  RCR   ,3     );                // Rotate right by cl/imm (with carry)
DEFNAME(OpcodeShiftRot   ,  SHL   ,4     );                // Shift left   by cl/imm                 (unsigned shift left )
DEFNAME(OpcodeShiftRot   ,  SHR   ,5     );                // Shift right  by cl/imm                 (unsigned shift right)
// OpcodeShiftRot          SH??   (6     );                // DO WHAT?
DEFNAME(OpcodeShiftRot   ,  SAR   ,7     );                // Shift Arithmetically right by cl/imm   (signed shift   right)

DEFNAME(OpcodeDoubleShift,  SHLD  ,0x0FA5,0x0FA4);         // Shift left  by cl/imm, filling opened bitpositions, by most significant bits of reg
DEFNAME(OpcodeDoubleShift,  SHRD  ,0x0FAD,0x0FAC);         // Shift right by cl/imm, filling opened bitpositions, by least significant bits of reg

DEFNAME(OpcodeBitScan    ,  BSF   ,0x0FBC);                // Bitscan forward
DEFNAME(OpcodeBitScan    ,  BSR   ,0x0FBD);                // Bitscan reversed

// Set Byte on Condition
DEFNAME(OpcodeSetcc      ,  SETO  ,0x0F90  );              // Set byte if overflow
DEFNAME(OpcodeSetcc      ,  SETNO ,0x0F91  );              // Set byte if not overflow
DEFNAME(OpcodeSetcc      ,  SETB  ,0x0F92  );              // Set byte if below                 (unsigned)
DEFNAME(OpcodeSetcc      ,  SETAE ,0x0F93  );              // Set byte if above or equal        (unsigned)
DEFNAME(OpcodeSetcc      ,  SETE  ,0x0F94  );              // Set byte if equal                 (signed/unsigned)
DEFNAME(OpcodeSetcc      ,  SETNE ,0x0F95  );              // Set byte if not equal             (signed/unsigned)
DEFNAME(OpcodeSetcc      ,  SETBE ,0x0F96  );              // Set byte if below or equal        (unsigned)
DEFNAME(OpcodeSetcc      ,  SETA  ,0x0F97  );              // Set byte if above                 (unsigned)
DEFNAME(OpcodeSetcc      ,  SETS  ,0x0F98  );              // Set byte if sign
DEFNAME(OpcodeSetcc      ,  SETNS ,0x0F99  );              // Set byte if not sign
DEFNAME(OpcodeSetcc      ,  SETPE ,0x0F9A  );              // Set byte if parity even
DEFNAME(OpcodeSetcc      ,  SETPO ,0x0F9B  );              // Set byte if parity odd
DEFNAME(OpcodeSetcc      ,  SETL  ,0x0F9C  );              // Set byte if less                  (signed  )
DEFNAME(OpcodeSetcc      ,  SETGE ,0x0F9D  );              // Set byte if greater or equal      (signed  )
DEFNAME(OpcodeSetcc      ,  SETLE ,0x0F9E  );              // Set byte if less or equal         (signed  )
DEFNAME(OpcodeSetcc      ,  SETG  ,0x0F9F  );              // Set byte if greater               (signed  );

DEFNAME(Opcode0Arg       ,  CWDE  ,0x98,DWORDPTR_ALLOWED); // Convert word  to dword  Copy sign (bit 15) of AX  into higher 16 bits of EAX
DEFNAME(Opcode0Arg       ,  CBW   ,CWDE,REGSIZE_WORD    ); // Convert byte  to word   Copy sign (bit 7)  of AL  into higher  8 bits of AX (AH)
DEFNAME(Opcode0Arg       ,  CDQ   ,0x99,DWORDPTR_ALLOWED); // Convert dword to qword  Copy sign (bit 31) of EAX into every bit of EDX
DEFNAME(Opcode0Arg       ,  CWD   ,CDQ ,REGSIZE_WORD    ); // Convert word  to dword  Copy sign (bit 15) of AX  into every bit of DX

#ifdef IS64BIT
DEFNAME(Opcode0Arg       ,  CDQE  ,CWDE,REGSIZE_QWORD);    // Sign extend EAX into RAX
DEFNAME(Opcode0Arg       ,  CQO   ,CDQ ,REGSIZE_QWORD);    // Sign extend RAX into RDX:RAX
#endif // IS64BIT

DEFNAME(StringInstruction,  MOVSB ,0xA4);
DEFNAME(StringInstruction,  CMPSB ,0xA6);
DEFNAME(StringInstruction,  STOSB ,0xAA);
DEFNAME(StringInstruction,  LODSB ,0xAC);
DEFNAME(StringInstruction,  SCASB ,0xAE);

DEFNAME(StringInstruction,  MOVSW ,MOVSB,REGSIZE_WORD);
DEFNAME(StringInstruction,  CMPSW ,CMPSB,REGSIZE_WORD);
DEFNAME(StringInstruction,  STOSW ,STOSB,REGSIZE_WORD);
DEFNAME(StringInstruction,  LODSW ,LODSB,REGSIZE_WORD);
DEFNAME(StringInstruction,  SCASW ,SCASB,REGSIZE_WORD);

DEFNAME(StringInstruction,  MOVSD ,MOVSB,REGSIZE_DWORD);
DEFNAME(StringInstruction,  CMPSD ,CMPSB,REGSIZE_DWORD);
DEFNAME(StringInstruction,  STOSD ,STOSB,REGSIZE_DWORD);
DEFNAME(StringInstruction,  LODSD ,LODSB,REGSIZE_DWORD);
DEFNAME(StringInstruction,  SCASD ,SCASB,REGSIZE_DWORD);

#ifdef IS64BIT
DEFNAME(StringInstruction,  MOVSQ ,MOVSB,REGSIZE_QWORD);
DEFNAME(StringInstruction,  CMPSQ ,CMPSB,REGSIZE_QWORD);
DEFNAME(StringInstruction,  STOSQ ,STOSB,REGSIZE_QWORD);
DEFNAME(StringInstruction,  LODSQ ,LODSB,REGSIZE_QWORD);
DEFNAME(StringInstruction,  SCASQ ,SCASB,REGSIZE_QWORD);
#endif // IS64BIT

DEFNAME(StringPrefix     ,  REP   ,0xF3);                  // Apply to INS, OUTS, MOVS, LODS, and STOS
DEFNAME(StringPrefix     ,  REPE  ,0xF3);                  // Apply to CMPS and SCAS instructions
DEFNAME(StringPrefix     ,  REPNE ,0xF2);                  // Apply to CMPS and SCAS instructions
