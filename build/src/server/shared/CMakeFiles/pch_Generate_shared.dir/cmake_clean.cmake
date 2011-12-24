FILE(REMOVE_RECURSE
  "CMakeFiles/pch_Generate_shared"
  "sharedPCH.h.gch/shared_Release.gch"
  "sharedPCH.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/pch_Generate_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
