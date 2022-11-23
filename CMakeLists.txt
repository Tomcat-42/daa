file(GLOB_RECURSE SOURCE CONFIGURE_DEPENDS
  include/**/*.hpp
  src/daa/*.cpp
  src/libdaa/*.cpp
)

pybind11_add_module(daa
  ${SOURCE}
  src/daa/daa.cpp
)

target_include_directories(daa PRIVATE include /usr/include /usr/local/include)

# target_include_directories(daa PRIVATE "${CMAKE_CURRENT_LIST_DIR}")

# target_compile_definitions(daa
#   PRIVATE
#     PYBIND11_USE_SMART_HOLDER_AS_DEFAULT
#     $<$<BOOL:${Geant4_gdml_FOUND}>:G4_HAS_GDML>
#     $<$<BOOL:${Geant4_ui_tcsh_FOUND}>:G4_HAS_TCSH>
#     $<$<BOOL:${Geant4_vis_opengl_x11_FOUND}>:G4_HAS_OPENGLX>
#     $<$<BOOL:${Geant4_vis_raytracer_x11_FOUND}>:G4_HAS_RAYTRACERX>
#     $<$<BOOL:${Geant4_motif_FOUND}>:G4_HAS_OPENGLXM>
#     $<$<BOOL:${Geant4_vis_opengl_win32_FOUND}>:G4_HAS_OPENGLWIN>
#     $<$<BOOL:${Geant4_qt_FOUND}>:G4_HAS_QT>
# )

# target_link_libraries( PRIVATE ${Geant4_LIBRARIES})
