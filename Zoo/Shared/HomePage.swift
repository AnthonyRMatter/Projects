//
//  ContentView2.swift
//  ZooGuide
//
//  Created by Joseph Sneifer on 5/5/22.
//
import SwiftUI

struct HomePage: View {
    var body: some View {
        NavigationView {
            
            // below by pablo
            VStack(){
                
                Spacer()
                Text("Chapman Zoo")
                    .fontWeight(.thin)
                    .font(.largeTitle)
                    .padding(.bottom, 30)
//                    .padding(.top, 100)
                
                
                VStack(spacing: 35) {
                    
                    Text("Please select an option.")
                        .font(.caption)
                    
                    NavigationLink(destination: HabitatView()) {
                        HStack {
                            Text("Habitats")
                                .font(.title)
                                .fontWeight(.thin)
                                .foregroundColor(.black)
                            Image(systemName: "pawprint.fill")
                                .foregroundColor(.black)
                            
                        }
                    }
                    .background(RoundedRectangle(cornerRadius: CGFloat(10)).foregroundColor(.green).opacity(0.5).frame(width: 165, height: 50, alignment: .center))
                    
                    NavigationLink(destination: MapView()) {
                        HStack {
                            Text("Map")
                                .font(.title)
                                .fontWeight(.thin)
                                .foregroundColor(.black)
                            Image(systemName: "globe.europe.africa.fill")
                                .foregroundColor(.black)
                        }

                    }
                    .background(RoundedRectangle(cornerRadius: CGFloat(10.0)).foregroundColor(.green).opacity(0.5).frame(width: 165, height: 50, alignment: .center))
                }
                .padding(30)
                .overlay(
                    RoundedRectangle(cornerRadius: 10).stroke(Color.gray.opacity(0.5), lineWidth: 2))
                
                

                
                
                Spacer()
                
                Text("Curated by Anthony Matter, Joe Sneifer, and Pablo Labbate.")
                    .foregroundColor(.black.opacity(0.5))
                    .fontWeight(.thin)
                    .font(.caption)
            }
            .frame(maxWidth: .infinity, maxHeight: .infinity)
            .background(.blue.opacity(0.1))
            .navigationTitle("Home")
            .navigationBarHidden(true)
            
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        HomePage()
    }
}
