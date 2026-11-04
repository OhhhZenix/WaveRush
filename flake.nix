{
  description = "A reproducible development environment example";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs; [
          go
          git
        ];

        ENV_VAR_EXAMPLE = "Hello from Nix!";

        shellHook = ''
          echo "========================================="
          echo " 🎉 Welcome to your Nix development shell!"
          echo " Loaded: Node $(node -v) & Go $(go version)"
          echo "========================================="
        '';
      };
    };
}
