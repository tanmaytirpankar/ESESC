file(REMOVE_RECURSE
  "CMakeFiles/qemu"
  "CMakeFiles/qemu-complete"
  "qemu/stampdir/qemu-install"
  "qemu/stampdir/qemu-mkdir"
  "qemu/stampdir/qemu-download"
  "qemu/stampdir/qemu-update"
  "qemu/stampdir/qemu-patch"
  "qemu/stampdir/qemu-configure"
  "qemu/stampdir/qemu-build"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/qemu.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
