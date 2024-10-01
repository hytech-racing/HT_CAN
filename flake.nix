# 🍳 cookin 👩‍🍳
{
  description = "flake for HT_CAN sym file for dbc output creation";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }@inputs:
    let
    makePackageSet = pkgs: {
        default = pkgs.ht_can_pkg;
        py_dbc_proto_gen_pkg = pkgs.py_dbc_proto_gen_pkg;
        proto_gen_pkg = pkgs.proto_gen_pkg;
      };
      ht_can_dbc_overlay = final: prev: {
        ht_can_pkg = final.callPackage ./default.nix { };
      };
      py_dbc_proto_gen_overlay = final: prev: {
        py_dbc_proto_gen_pkg = final.callPackage ./dbc_to_proto.nix { };
      };
      # proto_gen_overlay = final: prev: {
      #   proto_gen_pkg = final.callPackage ./dbc_to_proto_bin.nix { };
      # };
      pkgs = import nixpkgs {
        overlays = my_overlays;
        inherit system;
      };
      my_overlays = [
        ht_can_dbc_overlay
        py_dbc_proto_gen_overlay
        # proto_gen_overlay
      ];
      system = builtins.currentSystem;
      x86_pkgs = import nixpkgs {
        system = "x86_64-linux";
        overlays = [ self.overlays.default ];
      };

      arm_pkgs = import nixpkgs {
        system = "aarch64-linux";
        overlays = [ self.overlays.default ];
      };

      arch64-darwin_pkgs = import nixpkgs {
        system = "aarch64-darwin";
        overlays = [ self.overlays.default ];
      };

      x86-darwin_pkgs = import nixpkgs {
        system = "x86_64-darwin";
        overlays = [ self.overlays.default ];
      };

      packageSets = {
        "x86_64-linux" = makePackageSet x86_pkgs;
        "aarch64-linux" = makePackageSet arm_pkgs;
        "x86_64-darwin" = makePackageSet x86-darwin_pkgs;
        "aarch64-darwin" = makePackageSet arch64-darwin_pkgs;
        # Add more systems as needed
      };
    in {

      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;

      packages = packageSets;
      devShells.x86_64-linux.default = x86_pkgs.mkShell rec {
        # Update the name to something that suites your project.
        name = "nix-devshell";
        packages = with x86_pkgs; [
          # Development Tools
          python311Packages.cantools
          # ht_can_pkg 
          pkgs.py_dbc_proto_gen_pkg
          # proto_gen_pkg
        ];

      };

      devShells.aarch64-linux.default = arm_pkgs.mkShell rec {
        # Update the name to something that suites your project.
        name = "nix-devshell";
        packages = with arm_pkgs; [
          # Development Tools
          python311Packages.cantools
          # ht_can_pkg 
          py_dbc_proto_gen_pkg
          # proto_gen_pkg
        ];

      };

      devShells.aarch64-darwin.default = arch64-darwin_pkgs.mkShell rec {
        # Update the name to something that suites your project.
        name = "nix-devshell";
        packages = with arch64-darwin_pkgs; [
          # Development Tools
          #https://discourse.nixos.org/t/overriding-docheck-doesnt-work-with-python-package/14674
          (python311Packages.cantools.overridePythonAttrs (_: { doCheck = false; }))
          # ht_can_pkg 
          py_dbc_proto_gen_pkg
          # proto_gen_pkg
        ];

      };

      devShells.x86_64-darwin.default = x86-darwin_pkgs.mkShell rec {
        # Update the name to something that suites your project.
        name = "nix-devshell";
        packages = with x86-darwin_pkgs; [
          # Development Tools
          (python311Packages.cantools.overridePythonAttrs (_: { doCheck = false; }))
          # ht_can_pkg 
          py_dbc_proto_gen_pkg
          # proto_gen_pkg
        ];

      };

    };
}
