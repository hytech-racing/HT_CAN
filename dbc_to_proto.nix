{ lib, python312Packages }:

python312Packages.buildPythonApplication {
  pname = "py_dbc_proto_gen_pkg";
  version = "1.0.0";

  propagatedBuildInputs = [ (python312Packages.cantools.overridePythonAttrs (_: { doCheck = false; })) python312Packages.protobuf python312Packages.requests ];

  pyproject = true;
  build-system = [ python312Packages.setuptools ];
  src = ./dbc_to_proto;
}