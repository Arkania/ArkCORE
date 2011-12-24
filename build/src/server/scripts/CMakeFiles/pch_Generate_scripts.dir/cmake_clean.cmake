FILE(REMOVE_RECURSE
  "CMakeFiles/pch_Generate_scripts"
  "ScriptPCH.h.gch/scripts_Release.gch"
  "ScriptPCH.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/pch_Generate_scripts.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
