using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewLine : MonoBehaviour
{
    //public Rigidbody Rigidbody;

    private float up = 1;

    private void Update()
    {
        if (gameObject.transform.position.y >= 5 || gameObject.transform.position.y <= 0) up *= -5;
    
        gameObject.transform.position = new Vector3(gameObject.transform.position.x,gameObject.transform.position.y+0.02f*up, gameObject.transform.position.z);
   
    }
}
