//
//  ContentView.swift
//  Shared
//
//  Created by Joseph Sneifer on 5/4/22.
//
import SwiftUI

/*
 The structure HabitatView allows for the user to select between any of the four habitats that contains animals in the zoo. It is implemented so that each button to change between habitats is filled in with an image that represents that enviornment. For the ocean there is a water drop, rainforest there is leaf, desert there is a flame, and forest there is a pawprint.
 */
struct HabitatView: View {
    
    
    @State private var animalStore : AnimalStore = AnimalStore(animals: AnimalData)
    
    @State private var selection = 1
    
    var body: some View {
        TabView(selection: $selection) {
            VStack{
                RainforestPage(animalStore: $animalStore)
            }.tabItem {
                Image(systemName: "leaf.circle.fill")
                Text("Rainforest")
            }.tag(1)
            
            VStack{
                DesertPage(animalStore: $animalStore)
            }.tabItem {
                Image(systemName: "flame.circle.fill")
                Text("Desert")

            }.tag(2)
            
            VStack{
                OceanPage(animalStore: $animalStore)
            }.tabItem {
                Image(systemName: "drop.circle.fill")
                Text("Ocean")

            }.tag(3)
            
            VStack{
                ForestPage(animalStore: $animalStore)
            }.tabItem {
                Image(systemName: "pawprint.circle.fill")
                Text("Forest")

            }.tag(4)
        }
        .accentColor(colorToShow(selection: selection))
        .navigationTitle("")
        .navigationBarTitleDisplayMode(.inline)
        .onAppear {
            // correct the transparency bug for Tab bars
            let tabBarAppearance = UITabBarAppearance()
            tabBarAppearance.configureWithOpaqueBackground()
            UITabBar.appearance().scrollEdgeAppearance = tabBarAppearance
        } // source: https://www.hackingwithswift.com/forums/ios/tab-bar-transparent/10549
        // source above was used to fix issue of tab bar becoming transparent on navigation scene change
    }
    // done by pablo
    
}


// done by pablo
// changes the color of the tab icons depending on selection
func colorToShow(selection: Int) -> Color {
    let darkGreen = Color(red: 0.09, green: 0.49, blue: 0.20, opacity: 1.00)

    var colorToShow: Color {
        switch selection {
            case 1:
            return .green.opacity(0.7)
            case 2:
            return .brown.opacity(0.7)
            case 3:
                return .blue.opacity(0.7)
            case 4:
            return darkGreen.opacity(0.7)
            default:
                return .clear
        }
    }
    return colorToShow
}

/*
 The structure RainforestPage is meant to design the rainforest tab and what user sees on the tab. It also inherits from the AnimalData.json file and which ever animals have a habitat under Rainforest will be added to the list of animals in the Rainforest tab.
 */
struct RainforestPage: View {
    
    @Binding var animalStore: AnimalStore
    
    @State var rainforestAnimal: [Animal] = []
    
    var body: some View {
        
        VStack {
            Text("Rainforest")
                .font(.largeTitle)
                .fontWeight(.light)

            
            List {
                ForEach (animalStore.animals, id: \.self) { animal in
                    if(animal.habitat == "Rainforest") {
                        ListCell(animal: animal).foregroundColor(.green)
                    }
                }
            }

        }
        .background(.green.opacity(0.5))
        // UI by pablo and color logic
            
    }
}

/*
 The structure DesertPage is meant to design the rainforest tab and what user sees on the tab. It also inherits from the AnimalData.json file and which ever animals have a habitat under Desert will be added to the list of animals in the Desert tab.
 */
struct DesertPage: View {
    
    @Binding var animalStore: AnimalStore
    
    @State var desertAnimal: [Animal] = []
    
    var body: some View {
        
        VStack {
            Text("Desert")
                .font(.largeTitle)
                .fontWeight(.light)

            
            List {
                ForEach (animalStore.animals, id: \.self) { animal in
                    if(animal.habitat == "Desert") {
                        ListCell(animal: animal).foregroundColor(.brown)
                    }
                }
            }
        }
        .background(.brown.opacity(0.7))         // UI by pablo and color logic

    }
}

/*
 The structure OceanPage is meant to design the rainforest tab and what user sees on the tab. It also inherits from the AnimalData.json file and which ever animals have a habitat under Ocean will be added to the list of animals in the Ocean tab.
 */
struct OceanPage: View {
    
    @Binding var animalStore: AnimalStore
    
    @State var oceanAnimal: [Animal] = []
    
    var body: some View {
        
        VStack {
            Text("Ocean")
                .font(.largeTitle)
                .fontWeight(.light)

            
            List {
                ForEach (animalStore.animals, id: \.self) { animal in
                    if(animal.habitat == "Ocean") {
                        ListCell(animal: animal).foregroundColor(.blue)
                    }
                }
            }
        }
        .background(.blue.opacity(0.7))
        // UI by pablo and color logic

    }
}

/*
 The structure ForestPage is meant to design the rainforest tab and what user sees on the tab. It also inherits from the AnimalData.json file and which ever animals have a habitat under Forest will be added to the list of animals in the Forest tab.
 */
struct ForestPage: View {
    let darkGreen = Color(red: 0.09, green: 0.49, blue: 0.20, opacity: 1.00)
    @Binding var animalStore: AnimalStore
    
    @State var forestAnimal: [Animal] = []
    
    var body: some View {
        
        VStack {
            Text("Forest")
                .font(.largeTitle)
                .fontWeight(.light)

            List {
                ForEach (animalStore.animals, id: \.self) { animal in
                    if(animal.habitat == "Forest") {
                        ListCell(animal: animal).foregroundColor(darkGreen)
                    }
                }
                    
            }
        }
        .background(darkGreen.opacity(0.7))
        // UI by pablo and color logic

        
            
    }
}

/*
 The structure ListCell essentially lists the name of the animal under the details of that specific animal. An example of this would be when you click on the animal Jaguar, inside that tab under animal details, it will also display Jaguar.
 */
struct ListCell: View {
    var animal: Animal
    var body: some View {
        NavigationLink(destination: AnimalDetail(selectedAnimal: animal)) {
            Text(animal.species)
                .font(.title3)
                .fontWeight(.semibold)
                .padding()
        }
    }
}

struct HabitatView_Previews: PreviewProvider {
    static var previews: some View {
        HabitatView()
    }
}
