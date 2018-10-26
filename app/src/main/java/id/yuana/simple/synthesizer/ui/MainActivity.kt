package id.yuana.simple.synthesizer.ui

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import id.yuana.simple.synthesizer.R
import id.yuana.simple.synthesizer.util.toast
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        initView()
    }

    private fun initView() {
        btnStart.setOnClickListener {
            "start".toast(this@MainActivity)
        }

        btnStop.setOnClickListener {
            "stop".toast(this@MainActivity)
        }
    }


    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
