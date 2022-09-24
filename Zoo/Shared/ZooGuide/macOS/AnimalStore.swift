//
//  AnimalStore.swift
//  ZooGuide
//
//  Created by Joseph Sneifer on 5/4/22.
//

import SwiftUI
import Combine

class AnimalStore: ObservableObject {
    @Published var animals: [Animal]
    
    init (animals: [Animal] = []) {
        self.animals = animals
    }
}
