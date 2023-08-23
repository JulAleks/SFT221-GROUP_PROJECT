# SFT221 – Project README

## Project Overview
This repository contains the code and documentation for the SFT221 project, which involves designing and implementing a solution for a local delivery company. The goal of this project is to efficiently allocate packages to delivery trucks, ensuring that each package is assigned to a truck that can accommodate it and is closest to its destination. This README file provides an overview of the project, its objectives, and the algorithms used to achieve the desired outcomes.

## Learning Outcomes
The primary learning outcomes for this project are as follows:
1. Design and build a solution to a small problem.
2. Design the testing strategy for the problem.

## Project Description
### Problem Statement
You have been hired by a local delivery company that operates three different trucks on three different routes within your city. The city is represented as a 25 by 25 square grid, with the company's offices located at square 1A. The three delivery trucks initially follow a common path (blue), but then branch out to cover different parts of the neighborhood. Buildings where packages can be delivered are represented by black rectangles, while white areas indicate empty space.

### Package Allocation
When a customer requests a shipment, they provide the following information:
- Weight of the shipment in kilograms.
- Size of the required box in cubic meters.
- Destination building specified by a row number and column letter within a black rectangle.

Your task is to find an appropriate truck for each shipment, considering both the truck's capacity and its proximity to the destination. Trucks can divert slightly from their assigned routes to deliver packages, but they cannot drive through buildings. If multiple trucks are equidistant from the destination, choose the one with the most available space.

### Truck Capacity
All trucks have the following capacity limits:
- Maximum weight: 1000 kilograms.
- Maximum volume: 36 cubic meters.

Boxes for shipping come in sizes of 1/4 cubic meter, 1/2 cubic meter, and 1 cubic meter, and they are square-shaped.

### Distance Calculation
Determining the closest truck to a destination involves calculating Euclidean distances while considering obstacles (buildings) on the grid. The A* algorithm is used to find the shortest path between two points, accounting for building obstacles.

## The Shortest Path Algorithm
To determine the closest truck to a destination, the A* algorithm is employed. This algorithm uses Euclidean distance as a heuristic to guide the choice of the next move. It calculates the distance from the current position to the destination for all possible moves, then selects the move that minimizes this distance while avoiding buildings.

## The Overall Algorithm
The overall algorithm for package allocation follows these steps:
1. Follow the route for each truck.
2. At each square on a truck's route, calculate the Euclidean distance to the destination.
3. Select the truck with the minimum Euclidean distance for each shipment.
4. Calculate the shortest path from each truck's position to the destination.
5. If a truck cannot find a path to the destination, exclude it from delivery consideration.
6. Select the truck with the shortest path from its nearest point on the route to the destination.
7. Attempt to add the package to the selected truck.
8. If the selected truck cannot hold the package, try the next closest truck.
9. If no truck can accommodate the package, it will be placed in storage at the depot until the next day and marked as "Ships tomorrow."

## Project Execution
This project will run for one day. It will accept items for delivery until all trucks are full or until no more items arrive. Once this condition is met, the trucks will be dispatched, and the program will:
- Decide which truck the package will be placed in.
- Print out the destination where the truck will deliver the package.
- If the truck needs to divert from its route to deliver the package, it will print the diversion path.

## Getting Started
To get started with this project, follow these steps:
1. Clone this GitHub repository to your local machine.
2. Review the project documentation and code files.
3. Implement the required algorithms and functions to achieve the project's objectives.
4. Test the code thoroughly to ensure its correctness and efficiency.

## Testing
The success of this project relies on effective testing. Design a comprehensive testing strategy to validate the correctness and efficiency of your solution. Ensure that your tests cover various scenarios, including edge cases and obstacle avoidance.

## Contributing
If you would like to contribute to this project, please follow these guidelines:
- Fork the repository.
- Create a new branch for your feature or bug fix.
- Make your changes and thoroughly test them.
- Create a pull request detailing your changes.

## Acknowledgments
Duzon Audrey  - Project Manager & Technical Lead
Alekseev Julia- Lead Programmer
Eom Tae Yong - Programmer
Chan Ka Ying- Tester
Zeynalov Azad- Tester
