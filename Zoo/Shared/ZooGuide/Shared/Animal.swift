//
//  Animal.swift
//  ZooGuide
//
//  Created by Joseph Sneifer on 5/4/22.
//

import SwiftUI

struct Animal : Codable, Hashable {
    
    var species: String
    
    var habitat: String
    
    var kingdom: String
    
    var description: String
}
