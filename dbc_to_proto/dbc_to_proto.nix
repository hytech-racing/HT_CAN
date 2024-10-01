{ lib, python311Packages }:

python311Packages.buildPythonApplication {
  pname = "py_dbc_proto_gen";
  version = "1.0.0";

  propagatedBuildInputs = [ (python311Packages.cantools.overridePythonAttrs (_: { doCheck = false; }))
                            python311Packages.protobuf python311Packages.requests ];

  src = ./.;

   installPhase = ''
    mkdir -p $out/bin
    cp ./dbc_to_proto/dbc_to_proto.py $out/bin/dbc_to_proto
    chmod +x $out/bin/dbc_to_proto 
  '';
}