#!/usr/bin/env python3

def ft_garden_intro(name: str, height: int, age: int):
    """
    Display the plant information in garden
    """
    print(f"Plant: {name}")
    print(f"Height: {height}cm")
    print(f"Age: {age} days")


def main() -> None:
    print("--- Welcome to My Garden ---")
    ft_garden_intro("Rose", 25, 30)
    print()
    print("--- End of Program ---")


if __name__ == "__main__":
    main()
