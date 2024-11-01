# Byepervisor
---
## Summary
PS5 hypervisor exploit for <= 2.xx firmware. Two vulnerabilities and exploit chains are contained in the repo, they are independent of each other and either can be used. One exploit is provided mainly just for preservation (`/_old_jump_table_exploit`), only the primary exploit chain needs to be used (QA flags exploit).

**This research was presented at hardwear.io NL 2024, slides can be found [here](https://github.com/PS5Dev/Byepervisor/blob/main/Byepervisor_%20Breaking%20PS5%20Hypervisor%20Security.pdf). The talk will be published soon.**

**Jump Table Exploit**

The first exploit uses a vulnerability where hypervisor code jump tables are shared with the guest kernel, and is contained in `/_old_jump_table_exploit/`. By hijacking the jump table entry for the `VMMCALL_HV_SET_CPUID_PS4` hypercall, code execution in the hypervisor can be achieved. We run a ROP chain that disables Nested Paging (NPT) and Guest Mode Execute Trap (GMET), which allows us to disable eXecute Only Memory (XOM) aka `xotext` in the kernel Page Table Entries (PTEs) to dump it, as well as enabling write in the PTEs to hook/patch the kernel as well.

This method requires a fair number of gadgets and offsets, which is the main reason this exploit isn't the primary one. It also currently only breaks the hypervisor on the core the ROP chain runs on, the hypervisor is still active on other cores and would need to be disabled.

**QA Flags Exploit**

The primary and recommended exploit takes advantage of the fact that system Quality Assurance (QA) flags are shared between the hypervisor and the guest kernel. When the hypervisor initializes, the init code for constructing nested page tables will check QA flags for the System Level (SL) debugging flag. If this flag is set, the nested Page Table Entries (PTEs) will not have the `xotext` bit set for kernel .text pages, and further the kernel .text pages will also have the write bit set.

These flags are not reinitialized by the secure loader upon resume from sleep mode, though the hypervisor is. By setting the SL flag, putting the system to sleep, and resuming, we can edit the guest kernel's pagetables to make kernel .text pages read/writable, allowing dumping of the kernel and hooks/patches.

## Important Notes
- Currently only listed FW is supported for Homebrew Enabler (HEN), support for other firmware versions will be added at a later time.
- The exploit payload (byepervisor.elf) will need to be sent twice, once before suspending the system and again after resuming.
- You will have to put the system into rest mode manually yourself
- Kernel dump from QA flags exploit will not contain hypervisor's .data region at the moment, if this is important for you, dump using the jump table exploit after porting or disable nested paging first (this is a TODO)

## Currently included
- Kernel dumping code (commented out, running this code *will* panic the system as it will try to dump as much as it can before hitting unmapped memory)
- Code to decrypt system library SELFs over TCP
- Homebrew enabler (HEN) (fself+fpkg)

## Firmware Status
Completed: 1.00, 1.01, 1.02, 1.05, 1.12, 1.14, 2.00, 2.20, 2.25, 2.26, 2.30, 2.50, 2.70

## Build notes
This exploit payload is built using the [PS5-Payload-Dev SDK](https://github.com/ps5-payload-dev/sdk). Note also that the build for `hen/` is slightly special, as it gets compiled to a flat binary thats copied into a kernel code cave. The entirety of code in `hen/` runs in supervisor/kernel mode.

## How to use
1. Run the UMTX exploit chain in webkit or BD-J and run an ELF loader
2. Send `byepervisor.elf`
3. Put the system into rest mode
4. Power system back on
5. Send `byepervisor.elf` again (if you use John Tornblom's ELF loader, the ELF loader should continue to accept payloads after resume, if not the UMTX exploit will need to be run again)

## Future work
- [ ] Support more firmwares (offsets)
- [ ] Make it so `byepervisor.elf` only needs to be sent once
- [ ] Automatically suspend the system?
- [ ] Patch vmcbs with QA flags exploit to dump hypervisor data

## Credits / Shouts
- [ChendoChap](https://github.com/ChendoChap)
- [flatz](https://x.com/flat_z)
- [fail0verflow](https://fail0verflow.com/blog/)
- [Znullptr](https://twitter.com/Znullptr)
- [kiwidog](https://kiwidog.me/)
- [sleirsgoevy](https://x.com/sleirsgoevy)

## Discord
Those interested in contributing to PS5 research/dev can join a discord I have setup [here](https://discord.gg/kbrzGuH3F6).
