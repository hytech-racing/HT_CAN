{pkgs, py_dbc_proto_gen_pkg, ht_can_pkg, protobuf, }:

pkgs.stdenv.mkDerivation rec {
  name = "ht-proto-gen";
  
  src = builtins.filterSource (path: type: false) ./.;
  
  nativeBuildInputs = [ py_dbc_proto_gen_pkg ht_can_pkg protobuf ]; # Python as a build dependency
  
  # Define the build phase to execute the scripts
  buildPhase = ''
    # Run the Python script
    python3 dbc_to_proto.py ${ht_can_pkg}
  '';

  # Specify the output of the build process
  # In this case, it will be the generated file
  installPhase = ''
    mkdir -p ${ht_can_pkg}/proto
    cp hytech.proto ${ht_can_pkg}/proto
  '';
}