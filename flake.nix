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
        CC = "${pkgs.clang}/bin/clang";
        CXX = "${pkgs.clang}/bin/clang++";
        OBJCXX = "${pkgs.clang}/bin/clang++";

        packages = with pkgs; [
          # tools
          clang
          cmake
          gnumake
          pkg-config

          # libs
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
