#!/usr/bin/env python3

class Plant:
    """
    Represent a plant object

    Attributes:
        name (str): plant's name
        height_cm (int): height in cm
        age_days (int): age in days
    """

    def __init__(self, name: str, height_cm: int, age_days: int):
        """
        Initializing the plant with name, height and age
        """
        self.name = name
        self.height_cm = height_cm
        self.age_days = age_days

    def get_info(self) -> str:
        """
        Display the plant's information
        """
        return f"{self.name} ({self.height_cm}cm, {self.age_days} days)"


def main() -> None:
    """
    Entry point of the Plant Factory program.

    Create a list of plant data, initializes Plant objects from that data,
    and displays information about each created plant. Finallu, it prints
    the total number of plants created.
    """
    plant_data = [
        ("Rose", 25, 30),
        ("Oak", 200, 365),
        ("Cactus", 5, 90),
        ("Sunflower", 80, 45),
        ("Fern", 15, 120)
    ]

    plants = [Plant(name, height, age) for name, height, age in plant_data]

    print("=== Plant Factory Output ===")
    for plant in plants:
        print(f"Created: {plant.get_info()}")

    print()
    print(f"Total plants created: {len(plants)}")


if __name__ == "__main__":
    main()
