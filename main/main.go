package main

import (
	"fmt"
	"time"

	"github.com/sterren13/discord-ipc/client"
)

func main() {
	err := client.Login("863209778687377408")
	if err != nil {
		panic(err)
	}

	now := time.Now()
	err = client.SetActivity(client.Activity{
		State:      "Heyy!!!",
		Details:    "I'm running Custom Window Overlay",
		LargeImage: "largeimageid",
		LargeText:  "Custom Window Overlay",
		SmallImage: "smallimageid",
		SmallText:  "And this is the small image",
		Party: &client.Party{
			ID:         "-1",
			Players:    15,
			MaxPlayers: 24,
		},
		Timestamps: &client.Timestamps{
			Start: &now,
		},
		Buttons: []*client.Button{
			&client.Button{
				Label: "GitHub",
				Url:   "https://github.com/sterren13/discord-ipc",
			},
		},
	})

	if err != nil {
		panic(err)
	}

	// Discord will only show the presence if the app is running
	// Sleep for a few seconds to see the update
	fmt.Println("Sleeping...")
	time.Sleep(time.Second * 20)
}
