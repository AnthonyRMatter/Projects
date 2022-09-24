//
//  Animal.swift
//  ZooGuide
//
//  Created by Joseph Sneifer on 5/4/22.
//

import SwiftUI
/*
 The structure Animal is essentially meant to implement the contents of each Animal, which in this scenario are the species name, the habitat, the type of kingdom, the description of the animal, and the name of the image of the animal.
 */
struct Animal : Codable, Hashable {
    
    var species: String
    
    var habitat: String
    
    var kingdom: String
    //below by Anthony
    var description: String
    
    var imageName: String
}
