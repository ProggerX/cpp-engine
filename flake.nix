{
	inputs = {
		nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
	};
	outputs = {self, nixpkgs}:
	let system = "x86_64-linux";
	pkgs = import nixpkgs { inherit system; };
	in {
		devShells."${system}".default = pkgs.mkShell {
			packages = with pkgs; [
				SDL2
				SDL2_image
				gcc
				just
				bear
				pkgsCross.mingwW64.buildPackages.gcc
				pkgsCross.mingwW64.windows.mcfgthreads
			];
		};
	};
}
