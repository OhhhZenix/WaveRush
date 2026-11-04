{
  description = "A reproducible development environment example";

  # Pull the latest stable Nix packages repository
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { self, nixpkgs }:
    let
      # Define the system architecture (change if you are on an M-series Mac, etc.)
      system = "x86_64-linux"; 
      pkgs = import nixpkgs { inherit system; };
    in
    {
      # This defines what happens when you run `nix develop`
      devShells.${system}.default = pkgs.mkShell {
        # 1. Packages to load into the shell
        packages = with pkgs; [
          nodejs_20
          go
          git
        ];

        # 2. Environment variables to set automatically
        ENV_VAR_EXAMPLE = "Hello from Nix!";

        # 3. Code to run immediately when entering the shell
        shellHook = ''
          echo "========================================="
          echo " 🎉 Welcome to your Nix development shell!"
          echo " Loaded: Node $(node -v) & Go $(go version)"
          echo "========================================="
        '';
      };
    };
}
