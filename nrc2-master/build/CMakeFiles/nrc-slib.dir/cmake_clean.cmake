file(REMOVE_RECURSE
  "lib/libnrc.a"
  "lib/libnrc.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/nrc-slib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
