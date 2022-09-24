//
//  GameData.swift
//  Project2
//
//  Created by Joseph Sneifer on 4/13/22.
//

import Foundation
import UIKit
import SwiftUI

var AnimalData: [Animal] = loadJson("AnimalData.json")

/*
 The function loadJson essentially loads the json file AnimalData and if there are any complications, then a fatal error is executed that either displays that the file could not be led or it couldn't be parsed.
 */
func loadJson<T: Decodable>(_ filename: String) -> T {
    let data: Data
    
    guard let file = Bundle.main.url(forResource: filename, withExtension: nil)
            
    else {
        fatalError("\(filename) not found... ")
    }
    
    do {
        data = try Data(contentsOf: file)
    } catch {
        fatalError("Could not lead \(filename): \(error)")
    }
    
    do {
        return try JSONDecoder().decode(T.self, from: data)
    } catch {
        fatalError("Unable to parse \(filename): \(error)")
    }
}
