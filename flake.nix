{
  description = "WaveRush development environment";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        CC = "${pkgs.gcc}/bin/gcc";
        CXX = "${pkgs.gcc}/bin/g++";
        OBJCXX = "${pkgs.clang}/bin/clang++";

        packages = with pkgs; [
          clang
          cmake
          gcc
          gnumake
          ninja
          pkg-config
          alsa-lib
          libGL
          libx11
          libxcursor
          libxi
          libxinerama
          libxrandr
          libxxf86vm
        ];
      };
    };
}
