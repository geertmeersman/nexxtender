import hashlib
import sys
from pathlib import Path

def calculate_package_hash(full_url: str, domain: str = "esphome") -> Path:
    # Split the URL and ref if present
    if "@" in full_url:
        url, ref = full_url.rsplit("@", 1)
    else:
        url, ref = full_url, None

    # Construct the key from the URL and ref
    key = f"{url}@{ref}" if ref else url

    # Create a SHA-256 hash object and update with the key
    h = hashlib.new("sha256")
    h.update(key.encode())

    # Use the first 8 characters of the hash as the folder name
    hash_prefix = h.hexdigest()[:8]

    # Define the base directory
    base_dir = Path(f"./.{domain}/packages/")
    destination_path = base_dir / hash_prefix

    return destination_path

if __name__ == "__main__":
    if len(sys.argv) > 1:
        full_url = sys.argv[1]
    else:
        example_url = "https://github.com/geertmeersman/nexxtender@None"
        print(f"No URL provided. Example usage:\n    python3 calculate_esphome_package_path.py \"{example_url}\"")
        sys.exit(1)

    destination = calculate_package_hash(full_url)
    print(f"The calculated package directory path is: {destination}")
