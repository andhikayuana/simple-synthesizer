package id.yuana.simple.synthesizer.util

import android.content.Context
import android.widget.Toast

/**
 * @author Yuana andhikayuana@gmail.com
 * @since Oct, Sat 27 2018 04.43
 **/

fun Any.toast(context: Context, duration: Int = Toast.LENGTH_SHORT): Toast {
    return Toast.makeText(context, this.toString(), duration).apply { show() }
}