//
//  AppDelegate.swift
//  Example-Swift
//
//  Created by Mohammed Ennabah on 12/13/20.
//

import UIKit
import DapiConnect

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {



    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        // Override point for customization after application launch.
        let configs = DapiConfigurations(countries: ["SA"], environment: .sandbox)
        configs.postSuccessfulConnectionLoadingText = "Test loading text";
        configs.showLogos = true

        Dapi.start(appKey: "71a9779c3d1319b7381ebcb7ce79ab21e3a631256e7337a2db4956ddd4f6ac79",
                   clientUserID: "JohnDoe123",
                   configuration: configs) { (dapi, error) in
            
        }
        
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }


}

