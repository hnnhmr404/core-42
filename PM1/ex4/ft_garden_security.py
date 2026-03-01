#!/usr/bin/env python3

class SecurePlant:
    """
    Represent a plant object with protected attributes.

    Attributes:
        name (str): Plant's name
        _height_cm (int): Height of the plant in cm (protected)
        _age_days (int): Age of the plant in days (protected)
    """
    def __init__(self, name: str, height_cm: int = 0, age_days: int = 0):
        """
        Initializes a SecurePlant object.

        Sets the plant name and initializes height and age using secure setters
        to enforce validation rules.

        :param name: Plant's name
        :param height_cm: Initial height in cm (default: 0)
        :param age_days: Initial age in days (default: 0)
        """
        self.name = name
        self._height_cm = 0
        self._age_days = 0
        self.set_height(height_cm)
        self.set_age(age_days)

    def set_height(self, height: int) -> None:
        """
        Sets the height of the plant securely.

        Rejects negative values and prints a security warning.
        Ignores zero values.
        Accepts positive values and updates the height.

        :param height: New height in centimeters.
        :return: None
        """
        if height < 0:
            print(f"Invalid operation attempted: height {height}cm [REJECTED]")
            print("Security: Negative height rejected\n")
        elif height == 0:
            return
        else:
            self._height_cm = height
            print(f"Height updated: {self._height_cm}cm [OK]")

    def set_age(self, age: int) -> None:
        """
        Sets the age of the plant securely.

        Rejects negative values and prints a security warning.
        Ignores zero values.
        Accepts positive values and updates the age.

        :param age: New age in days.
        :return: None
        """
        if age < 0:
            print(f"Invalid operation attempted: age {age} days [REJECTED]")
            print("Security: Negative age rejected\n")
        elif age == 0:
            return
        else:
            self._age_days = age
            print(f"Age updated: {self._age_days} days [OK]")

    def get_height(self) -> int:
        """
        Returns the current height of the plant.

        :return: Height in centimeters.
        """
        return self._height_cm

    def get_age(self) -> int:
        """
        Returns the current age of the plant.

        :return: Age in days.
        """
        return self._age_days

    def get_info(self) -> str:
        """
        Returns a formatted string containing the plant's information.

        :return: A string in the format "Name (heightcm, age days)".
        """
        return f"{self.name} ({self._height_cm}cm, {self._age_days} days)"


def main() -> None:
    """ Entry point of Garden Security System """
    print("=== Garden Security System ===")
    rose = SecurePlant("Rose")
    print(f"Plant created: {rose.name}")

    rose.set_height(25)
    rose.set_age(30)
    print()

    rose.set_height(-5)
    rose.set_age(-10)

    print(f"Current plant: {rose.get_info()}")


if __name__ == "__main__":
    main()
