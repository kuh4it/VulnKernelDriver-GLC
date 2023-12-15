# VulnKernelDriver

Signed by ASUS

Usage: driver mapper, syscall watcher, primitive arbitrary r/w, etc..

Routines:
```cpp
//
// Stripped from ProjectKZM
// Device.cpp: 82
//
DispatchRoutine.Get( DriverImage + 0x1AC0 );
WriteMsrIoctl.Register( 0x8010205C );
ReadMsrIoctl.Register( 0x80102054 );
CopySafeIoctl.Register( 0x80102050 );
UnmapShadowIoctl.Register( 0x80102044 );
MapShadowIoctl.Register( 0x80102040 );
```
