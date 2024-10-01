# 🍳 cookin 👩‍🍳
{
  description = "Flake for building the DBC to Proto executable";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.11";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }@inputs:
    let
      # Import the necessary packages
      pkgs = import nixpkgs { system = "x86_64-linux"; };
      py_dbc_proto_gen_overlay = final: prev: {
        py_dbc_proto_gen_pkg = final.callPackage ./dbc_to_proto.nix { };
      };
      my_overlays = [
        py_dbc_proto_gen_overlay
      ];
    in {
      # Expose the default package
      defaultPackage.x86_64-linux = ./dbc_to_proto.nix;

      # Create a development shell
      devShells.x86_64-linux.default = pkgs.mkShell {
        buildInputs = [
          pkgs.python311Packages.cantools
          pkgs.python311Packages.protobuf
          pkgs.python311Packages.requests
        ];
      };
    };
}