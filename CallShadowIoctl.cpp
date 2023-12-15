//
// Shadow call example stripped from driver
//
if ( ValidMemoryRange(this->NewObject) )
{
  if ( ObtainIoctl(Irp).Match(IO_MAP_SHADOW) ) // 0x80102040
  {
      if ( (int)GLC::ZwQueryInformationProcess(this->NewObject) < 0 || !Descriptor )
        goto Cleanup;
      GLC::CopyMemory(Src, ShadowPage, MappedMemory);
      MappedMemory = GLC::MapShadowPhysMem((union _LARGE_INTEGER)Src[1], Src[0], &vQuadPart, &Handle, &BytesRead);
      if ( !MappedMemory >= 0 )
      {
        GLC::CopyMemory(ShadowPage, Src, MappedMemory);
        GetBuffer(Irp) = MappedMemory;
      }
  }
}
