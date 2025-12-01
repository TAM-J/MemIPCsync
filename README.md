# Shared Memory IPC (shituf)

## Description
This project demonstrates Inter-Process Communication (IPC) using Windows File Mapping (shared memory) to synchronize between processes. It waits for a specific character ('*') to appear at the start of the mapped memory buffer before exiting.

## Key Concepts
* `CreateFileA`
* `CreateFileMappingA`
* `MapViewOfFile`
* Simple Busy-Wait Synchronization
