file(REMOVE_RECURSE
  "CMakeFiles/regression"
  "CMakeFiles/regression-complete"
  "gold/stampdir/regression-install"
  "gold/stampdir/regression-mkdir"
  "gold/stampdir/regression-download"
  "gold/stampdir/regression-update"
  "gold/stampdir/regression-patch"
  "gold/stampdir/regression-configure"
  "gold/stampdir/regression-build"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/regression.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
