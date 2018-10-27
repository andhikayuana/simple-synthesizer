package id.yuana.simple.synthesizer.ui

import android.content.Context
import android.media.AudioManager
import android.os.Build
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import id.yuana.simple.synthesizer.R
import id.yuana.simple.synthesizer.util.toast
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        initSampleRateAndFrames()
        initAudioEngine()
        initView()
    }

    private fun initSampleRateAndFrames() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN_MR1) {
            val audioManager = getSystemService(Context.AUDIO_SERVICE) as AudioManager

            val sampleRateStr = audioManager.getProperty(AudioManager.PROPERTY_OUTPUT_SAMPLE_RATE)
            val defaultSampleRate = sampleRateStr.toInt()

            val framesPerBurstStr = audioManager.getProperty(AudioManager.PROPERTY_OUTPUT_FRAMES_PER_BUFFER)
            val defaultFramesPerBurst = framesPerBurstStr.toInt()

            setDefaultSampleRate(defaultSampleRate)
            setDefaultFramesPerBurst(defaultFramesPerBurst)
        }
    }

    private fun initView() {
        btnStart.setOnClickListener {
            "start".toast(this@MainActivity)
            setToneOn(true)
        }

        btnStop.setOnClickListener {
            "stop".toast(this@MainActivity)
            setToneOn(false)
        }
    }


    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

    private external fun setToneOn(isOn: Boolean)

    private external fun initAudioEngine()

    private external fun setDefaultSampleRate(sampleRate: Int)

    private external fun setDefaultFramesPerBurst(framesPerBurst: Int)

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
