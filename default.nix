{ pkgs, python311Packages, fetchPypi }:

pkgs.stdenv.mkDerivation rec {
  name = "ht_can_pkg";

  src = ./PCAN_project;

  buildInputs = [
    # (python311Packages.cantools.overridePythonAttrs (old: {
    #   src = fetchPypi {
    #     pname = "cantools";
    #     version = "39.4.4";
    #     hash = "sha256-bo6Ri2ZxpiqfOZBUbs5WI+Hetx3vsc74WplVrDAdqZ4=";
    #   };
    #   doCheck = false;
    # }))
    python311Packages.cantools
  ]; # Python as a build dependency

  propagatedBuildInputs = buildInputs;

  nativeBuildInputs = buildInputs;

  # Define the build phase to execute the scripts
  buildPhase = ''
    cantools convert hytech.sym hytech.dbc
  '';

  # Specify the output of the build process
  # In this case, it will be the generated file
  installPhase = ''
    mkdir -p $out
    mv hytech.dbc $out/hytech.dbc
  '';
}
